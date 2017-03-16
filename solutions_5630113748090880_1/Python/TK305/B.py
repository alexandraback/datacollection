if __name__ == "__main__":
    with open("B-large.in", 'r') as inputf:
        outputf=open("B-large.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            n = int (line)
            cur_missing = []

            for j in range(1, 2*n):
                line = inputf.readline().rstrip('\n')
                cur_grid = [int(item) for item in line.split(' ')]
                for soldier in cur_grid:
                    if soldier in cur_missing:
                        cur_missing.remove(soldier)
                    else:
                        cur_missing.append(soldier)

            cur_missing.sort()
            missing_sol = " ".join([str(item) for item in cur_missing])

            result = "Case #{0}: {1}".format(i, missing_sol)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")