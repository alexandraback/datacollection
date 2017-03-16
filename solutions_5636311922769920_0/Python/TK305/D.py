if __name__ == "__main__":
    with open("D-small-attempt0.in", 'r') as inputf:
        outputf=open("D-small.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip("\n")
            data = line.split(" ")

            k = int(data[0])
            positions = " ".join([str(j+1) for j in range(k)])
            result = "Case #{0}: {1}".format(i, positions)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")