input_file = "A-small-attempt0.in"
output_file = "A-small-attempt0.out"

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
    tcs.append(int(sl))
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def GetAllDigits(N):
    if N == 0:
        return [0]
    r = []
    n = N
    while n > 0:
        r.append(n % 10)
        n = n / 10
    return r

def SolveTestCase(N):
    if N == 0:
        return "INSOMNIA"
    found = []
    for d in range (0, 10):
        found.append(False)
    found_count = 0
    delta = N
    while found_count < 10:
        ds = GetAllDigits(N)
        c = 0
        for d in ds:
            if c == 2:
                break
            if not found[d]:
                found[d] = True
                found_count += 1
        c += 1
        N = N + delta
    return N - delta

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

