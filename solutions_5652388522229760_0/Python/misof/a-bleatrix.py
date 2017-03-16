T = int(input())
for tid in range(1,T+1):
    N = int(input())
    if N == 0:
        print('Case #{}: INSOMNIA'.format(tid))
        continue
    seen = set()
    said = 0
    while True:
        said += N
        for x in str(said): seen.add(x)
        if len(seen) == 10:
            print('Case #{}: {}'.format(tid,said))
            break
