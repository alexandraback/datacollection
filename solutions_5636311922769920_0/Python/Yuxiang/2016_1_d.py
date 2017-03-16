# Problem D. Fractiles


def to_int(l, base):
    res = 0
    scale = 1
    for val in l[::-1]:
        res += scale * int(val)
        scale *= base
    return res


t = int(input())

cases = []
for i in range(t):
    cases.append(tuple(map(int, input().split(' '))))

for index, val in enumerate(cases): 
    k, c, s = val
    if c * s < k:
        print("Case #{}: {}".format(index + 1, "IMPOSSIBLE"))
    else:
        nb_students = (k + c - 1) // c
        choices = [i % k for i in range(nb_students * c)]
        points = [to_int(choices[i::nb_students], k) + 1 for i in range(nb_students)]
        print("Case #{}: {}".format(index + 1, ' '.join(map(str, points))))
