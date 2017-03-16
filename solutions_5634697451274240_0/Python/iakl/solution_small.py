input_file = "B-small-attempt0.in"
output_file = "B-small-attempt0.out"

in_f = open(input_file)
T_read = False
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    tcs.append(sl)
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def SolveTestCase(s):
    if len(s) == 0:
        return 0
    count= 1
    cch = s[0]
    for i in range(1, len(s)):
        if s[i] != s[i - 1]:
            count += 1
            cch = s[i]
    if s[len(s) - 1] == '+':
        return count - 1
    else:
        return count

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

