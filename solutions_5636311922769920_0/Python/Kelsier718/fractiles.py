# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    k, c, s = [int(s) for s in input().split(" ")]  # read a list of integers, 3 in this case
    if k > c * s:
        print("Case #{}: IMPOSSIBLE".format(i))
    else:
        q, r = int(k/c), k%c
        #print("q={},r={}".format(q,r))
        integers = [(1+sum((l*c+j)*k**(c-1-j) for j in range(c))) for l in range(q)]
        if r != 0:
            integers.append(1+sum((q*c+j)*k**(c-1-j) for j in range(r)))
        print("Case #{}: ".format(i) + " ".join(str(e) for e in integers))
        #print("Case #{}: {} {}".format(i, k + c, k * s))
        # check out .format's specification for more formatting options
