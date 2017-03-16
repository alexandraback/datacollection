input_file = "A-small-attempt"
input_file += raw_input("Input file number and file extension:\n")
output_file = "output"+input_file+".txt"



inp = open(input_file, 'r')
out = open(output_file, 'w')
T = int(inp.readline())

for test in range(1, T + 1):
    [A, B] = [int(item) for item in inp.readline().split()]
    p = [float(item) for item in inp.readline().split()]
    prod = [1.0]
    before = 1.0
    for prob in p:
        before *= prob
        prod.append(before)
    ans = min(2.0+B, min(A-2*i+B+1.0+(1.0-prod[i])*(B+1) for i in range(A+1)))
    out.write("Case #" + str(test) + ": " + str(ans) + "\n")


out.close()
inp.close()
print "Done!"
