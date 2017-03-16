t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    n = [s for s in str(input())]  # read a list of integers, 2 in this case

    ind = 0

    while ind < len(n)-1:
        if n[ind] == n[ind + 1]:
            n.pop(ind + 1)
            continue
        ind += 1
    ans = len(n) - 1 if n[-1] == '+' else len(n)
    print("Case #{}: {}".format(i, ans))