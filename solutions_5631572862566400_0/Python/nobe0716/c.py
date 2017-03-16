__author__ = 'sunghyo.jung'


def is_happy(bff, circle):
    l = len(circle)
    if l < 2:
        return False
    for i in range(1, l - 1):
        if circle[i - 1] not in bff[circle[i]] and circle[i + 1] not in bff[circle[i]]:
            return False
    if circle[l - 1] not in bff[circle[0]] and circle[1] not in bff[circle[0]]:
        return False
    if circle[0] not in bff[circle[l - 1]] and circle[l - 2] not in bff[circle[l - 1]]:
        return False

    return True

def search_next_child(n, bff, bff_reverse, circle, child_set):
    first_child = circle[0]
    last_child = circle[len(circle) - 1]
    v = 0
    # if first_child in bff[last_child] or (len(circle) >= 2 and circle[len(circle) - 2] in bff[last_child]):
    if is_happy(bff, circle):
        # print(circle)
        v = len(circle)

    # print(circle)
    candidates = set()
    candidates.update(bff[last_child])
    # if len(circle) >= 2 and circle[len(circle) - 2] in bff[last_child]:
    candidates.update(bff_reverse[last_child])

    for candidate in candidates:
        if candidate in child_set:
            child_set.remove(candidate)
            v = max([v, search_next_child(n, bff, bff_reverse, circle + [candidate], child_set)])
            child_set.add(candidate)

    return v


def largest(n, bff, bff_reverse):
    v = 0
    for i in range(1, n + 1):
        child_set = set(range(1, n + 1))
        child_set.remove(i)
        circle = [i]
        v = max([v, search_next_child(n, bff, bff_reverse, circle, child_set)])
    return v


num_test_case = int(input().strip())
# num_test_case = 1
for t in range(1, num_test_case + 1):
    n = int(input().strip())
    f = list(map(int, input().strip().split()))
    # n = 10
    # f = list(map(int, "7 8 10 10 9 2 9 6 3 3".strip().split()))
    bff = [set() for x in range(0, n + 1)]
    bff_reverse = [set() for x in range(0, n + 1)]

    for i in range(len(f)):
        bff[i + 1].add(f[i])
        bff_reverse[f[i]].add(i + 1)

    ans = largest(n, bff, bff_reverse)


    print("Case #%d: %d" % (t, ans))