if __name__ == "__main__":
    with open("B-small-attempt0.in", 'r') as inputf:
        outputf=open("B-small.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            cur_state = inputf.readline().rstrip('\n')
            count = 0

            while cur_state.find('-') != -1:
                cur_top = cur_state[0]
                if cur_top == '+':
                    ind = cur_state.find('-')
                    new_state = []
                    for j in range(ind):
                        new_state.append('-')
                    new_state.append(cur_state[ind:])
                    cur_state = "".join(new_state)
                else:
                    ind = cur_state.find('+')
                    if ind < 0:
                        ind = len(cur_state)
                    new_state = []
                    for j in range(ind):
                        new_state.append('+')
                    new_state.append(cur_state[ind:])
                    cur_state = "".join(new_state)
                count = count + 1

            result = "Case #{0}: {1}".format(i, count)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")