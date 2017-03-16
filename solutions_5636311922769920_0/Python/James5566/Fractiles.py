# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    # read a list of integers, 2 in this case
    K, C ,S = [int(s) for s in input().split(" ")]
    if K == 1:
        answer = '1'
    else:
        if C == 1:
            if S < K:
                answer = 'IMPOSSIBLE'
            else:
                answer = ' '.join(str(i) for i in range(1, K+1))
        elif S <= K-2:
            answer = 'IMPOSSIBLE'
        else:
            answer = ' '.join(str(i) for i in range(2, K+1))


    print("Case #{}: {}".format(i, answer))
    # check out .format's specification for more formatting options