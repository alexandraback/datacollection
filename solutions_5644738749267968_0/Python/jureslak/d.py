import bisect
def war(naomi, ken):
    k, n = 0, 0
    for i in naomi:
        kidx = bisect.bisect_right(ken, i)
        kc = ken.pop(kidx%len(ken))

        k += kc > i;
        n += i > kc;
    return k, n

def dwar(naomi, ken):
    return 1

for tt in range(int(input())):
    n = int(input())
    naomi = list(map(float, input().split()))
    ken = list(map(float, input().split()))
    naomi.sort()
    ken.sort()

    _, w = war(list(naomi), list(ken))
    dw, _ = war(list(ken), list(naomi))

    print("Case #{}: {} {}".format(tt+1,dw,w))
