cases = int(input())
for case in range(1, cases+1):
    r, c, w = [int(x) for x in input().split()]
    if w==1:
        print("Case #{}: {}".format(case, r*c))
        continue
    
    print("Case #{}: {}".format(case, r*(c//w)+w-(1 if c%w==0 else 0)))
