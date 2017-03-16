if __name__ == "__main__":
    with open("B-large.in", 'r') as inputf:
        outputf=open("B-large.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            cur_state = inputf.readline().rstrip('\n')
            count = 0
            cur_char = cur_state[0]

            for j in range(len(cur_state)):
                if cur_state[j] != cur_char:
                    count += 1
                    cur_char = cur_state[j]

            if cur_char == "-":
                count += 1

            result = "Case #{0}: {1}".format(i, count)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")