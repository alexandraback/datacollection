def solve(a, b):
    queue = [(0, 0, a, b)]
    min_diff = float('inf')
    best_a = float('inf')
    best_b = float('inf')

    while queue:
        pa, pb, sa, sb = queue.pop()
        if len(sa) == 0:
            if abs(pa-pb) < min_diff:
                min_diff = abs(pa-pb)
                best_a = pa
                best_b = pb
            elif abs(pa-pb) == min_diff:
                if best_a > pa:
                    best_a = pa
                    best_b = pb
                elif best_a == pa:
                    if best_b > pb:
                        best_b = pb
            continue
        if pa > pb:
            if sa[0] == '?':
                pa = pa * 10
            else:
                pa = pa * 10 + int(sa[0])
            if sb[0] == '?':
                pb = pb * 10 + 9
            else:
                pb = pb * 10 + int(sb[0])
            queue.append((pa, pb, sa[1:], sb[1:]))
        elif pa < pb:
            if sa[0] == '?':
                pa = pa * 10 + 9
            else:
                pa = pa * 10 + int(sa[0])
            if sb[0] == '?':
                pb = pb * 10
            else:
                pb = pb * 10 + int(sb[0])
            queue.append((pa, pb, sa[1:], sb[1:]))
        else:
            if sa[0] == '?' and sb[0] == '?':
                queue.append((pa * 10, pb * 10, sa[1:], sb[1:]))
                queue.append((pa * 10, pb * 10 + 1, sa[1:], sb[1:]))
                queue.append((pa * 10 + 1, pb * 10, sa[1:], sb[1:]))
            elif sa[0] == '?' and sb[0] != '?':
                if int(sb[0]) > 0:
                    queue.append(
                        (pa * 10 + int(sb[0]) - 1, pb * 10 + int(sb[0]), sa[1:], sb[1:]))
                if int(sb[0]) < 9:
                    queue.append(
                        (pa * 10 + int(sb[0]) + 1, pb * 10 + int(sb[0]), sa[1:], sb[1:]))
                queue.append(
                    (pa * 10 + int(sb[0]), pb * 10 + int(sb[0]), sa[1:], sb[1:]))
            elif sa[0] != '?' and sb[0] == '?':
                if int(sa[0]) > 0:
                    queue.append(
                        (pa * 10 + int(sa[0]), pb * 10 + int(sa[0]) - 1, sa[1:], sb[1:]))
                if int(sa[0]) < 9:
                    queue.append(
                        (pa * 10 + int(sa[0]), pb * 10 + int(sa[0]) + 1, sa[1:], sb[1:]))
                queue.append(
                    (pa * 10 + int(sa[0]), pb * 10 + int(sa[0]), sa[1:], sb[1:]))
            elif sa[0] != '?' and sb[0] != '?':
                pa = pa * 10 + int(sa[0])
                pb = pb * 10 + int(sb[0])
                queue.append((pa, pb, sa[1:], sb[1:]))
    return best_a, best_b


TESTCASE = int(input())
for test in range(TESTCASE):
    a, b = input().split()
    length = len(a)
    va, vb = solve(a, b)
    ans = ('0' * length + str(va))[-length:] + \
        ' ' + ('0' * length + str(vb))[-length:]
    print('Case #' + str(test + 1) + ':', ans)
