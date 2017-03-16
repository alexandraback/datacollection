t = int(input())

def brute(s, i):
    if i < len(s):
        if s[i] == '?':
            for dig in range(10):
                yield from brute(s[:i] + str(dig) + s[i+1:], i + 1)
        else:
            yield from brute(s, i + 1)
    else:
        yield s

def diff(a, b):
    return abs(int(a) - int(b))

for q in range(1, t+1):
    a, b = input().split()

    best_a = None
    best_b = None

    for filled_a in brute(a, 0):
        for filled_b in brute(b, 0):
            if best_a is None:
                best_a = filled_a
                best_b = filled_b
            elif diff(filled_a, filled_b) < diff(best_a, best_b):
                best_a = filled_a
                best_b = filled_b
            elif diff(filled_a, filled_b) == diff(best_a, best_b):
                if int(filled_a) < int(best_a):
                    best_a = filled_a
                    best_b = filled_b
                elif int(filled_a) == int(best_a) and int(filled_b) < int(best_b):
                    best_a = filled_a
                    best_b = filled_b

    print('Case #{}: {} {}'.format(q, best_a, best_b))
