if __name__ == "__main__":
    with open("A-large.in", 'r') as inputf:
        outputf=open("A-large.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            newword = ""
            cur_char = ""

            for char in line:
                if char >= cur_char:
                    newword = char + newword
                    cur_char = char
                else:
                    newword = newword + char

            result = "Case #{0}: {1}".format(i, newword)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")