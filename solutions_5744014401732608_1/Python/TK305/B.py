if __name__ == "__main__":
    with open("B-large.in", 'r') as inputf:
        outputf=open("B-large.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            temp = line.split(" ")
            B = int(temp[0])
            M = int(temp[1])
            remaining = M
            n = B - 2
            max_possible = 2**(B - 2)

            if M > max_possible:
                result = "Case #{0}: IMPOSSIBLE".format(i)
            elif M == max_possible:
                bridge = ''
                for row in range(B):
                    cur = ''
                    if row == B - 1:
                        for col in range(B):
                            cur += '0'
                    else:
                        for col in range(row + 1):
                            cur += '0'
                        for col in range(B - row - 1):
                            cur += '1'
                        cur += "\n"
                    bridge += cur
                result = "Case #{0}: POSSIBLE\n{1}".format(i, bridge)
            else:
                bridge = ""
                first_row = ""
                for row in range(B):
                    cur = ""
                    if row == 0:
                        cur = "0"*B
                        bridge += cur
                    elif row == B - 1:
                        first_row = "0" + first_row + ("1" if remaining else "0")
                        bridge = first_row + "\n" + bridge
                    else:
                        if remaining > 0:
                            cur = ""
                            for col in range(B - row):
                                cur += "0"
                            for col in range(row):
                                cur += "1"
                            bridge = cur + "\n" + bridge
                            first_row = ("0" if remaining % 2 == 0 else "1") + first_row
                        else:
                            cur = "0" * B
                            bridge = cur + "\n" + bridge
                            first_row = "0" + first_row
                        remaining = remaining // 2
                result = "Case #{0}: POSSIBLE\n{1}".format(i, bridge)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")