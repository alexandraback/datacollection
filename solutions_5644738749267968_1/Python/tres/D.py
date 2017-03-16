from collections import deque
for t in range(1,int(input())+1):
    N = int(input())
    naomi, ken = (sorted(map(float, input().split())) for _ in range(2))
    ken_war = deque(ken)
    
    deceitful, war = 0, 0

    while naomi:
        n = naomi.pop()
        while ken:
            if n > ken.pop():
                deceitful += 1
                break
        if n > ken_war[-1]:
            war += 1
            ken_war.popleft()
        else:
            ken_war.pop()

    print('Case #{0}: {1} {2}'.format(t, deceitful, war))
