def solve(a):
    return sum(x!=y for x,y in zip(a,a[1:]+'+'))

for t in range(int(input())):
    print("Case #{}: {}".format(t+1, solve(input())))
