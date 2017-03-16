input = open('C-small-attempt0.in', 'r')
output = open('C-small-attempt0.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    c, d, v = map(int, input.readline().rstrip().split())
    denoms = list(map(int, input.readline().rstrip().split()))
    ans = 0
    for ammount in range(1, v + 1):
        remain = ammount
        for i in range(len(denoms) - 1, -1, -1):
            if remain >= denoms[i]:
                remain -= denoms[i]
        if remain > 0:
            if remain not in denoms:
                ans += 1
                denoms.append(remain)
                denoms.sort()
            else:
                i = denoms.index(remain)
                while ammount in denoms:
                    ammount -= 1
                ans += 1
                denoms.append(ammount)
                denoms.sort()
            
    output.write("Case #" + str(test + 1) + ": " + str(ans) + "\n")

input.close()
output.close()