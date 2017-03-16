myInput = open('A-small-attempt0.in', 'r')
myOutput = open('output.txt', 'w')
T = myInput.readline();
case = 0
for S in myInput:
    case += 1
    ans = ""
    for i in range(0, len(S)):
        if i == 0:
            ans += S[i]
        elif S[i] >= ans[0]:
            ans = S[i] + ans
        else:
            ans += S[i]
    myOutput.write("Case #%d: %s" % (case, ans))
myInput.close()
myOutput.close()
