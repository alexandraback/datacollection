INPUT_FILE = "B-large.in"
OUTPUT_FILE = "B-large.out"
with open(INPUT_FILE) as f:
    with open(OUTPUT_FILE, "w") as of:
        cases = int(f.readline())
        for case in range(1, cases+1):
            numlines = int(f.readline())
            lines = {}
            for ele in range(2*numlines-1):
                tList = map(int, f.readline().split())
                for num in tList:
                    if num in lines:
                        lines[num] += 1
                    else:
                        lines[num] = 1
            cList = []
            for key in lines:
                if lines[key] % 2 == 1:
                    cList.append(key)
            of.write("Case #{0}: {1}".format(case, " ".join([str(x) for x in sorted(cList)])))
            of.write("\n")
