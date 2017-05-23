# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    # read a list of integers, 2 in this case
    n = [int(s) for s in input().split(" ")]

    k = n[0]
    c = n[1]
    s = n[2]

    if k == 1:
        ans = '1'
    else:
        if c == 1:
            if s < k:
                ans = 'IMPOSSIBLE'
            else:
                ans = ' '.join(str(i) for i in range(1, k+1))
        elif s <= k-2:
            ans = 'IMPOSSIBLE'
        else:
            ans = ' '.join(str(i) for i in range(2, k+1))


    print("Case #{}: {}".format(i, ans))
    # check out .format's specification for more formatting options