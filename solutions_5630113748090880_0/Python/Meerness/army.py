
with open("input.txt") as f:
    with open("output.txt", "w") as outf:
        height_set = set()
        case = 0
        lines = 0
        line_num = 0
        for i, line in enumerate(f):
            if i == 0:
                continue
            elif line_num == lines:
                line_length = int(line)
                lines = line_length*2 -1
                line_num = 0
            else:
                for n in line.strip().split(" "):
                    n = int(n)
                    if int(n) in height_set:
                        height_set.remove(int(n))
                    else:
                        height_set.add(int(n))
                line_num += 1
                if line_num == lines:
                    case+=1
                    line = " ".join([str(x) for x in sorted(list(height_set))])
                    outf.write("Case #" + str(case) + ": " + line + "\n")
                    height_set = set()




