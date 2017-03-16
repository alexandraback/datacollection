if __name__ == "__main__":
    with open("A-large.in", 'r') as inputf:
        outputf=open("A-large.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            n = int(line)
            not_seen = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
            current_n = n

            if n != 0:
                j = 1
                while not_seen and j < 10**6:
                    current_n = n * j
                    num = current_n
                    while num > 0:
                        digit = num % 10
                        if digit in not_seen:
                            not_seen.remove(digit)
                        num = num // 10
                    j = j + 1

            if not not_seen:
                result = "Case #{0}: {1}".format(i, current_n)
                outputf.write(result)
            else:
                result = "Case #{0}: INSOMNIA".format(i, current_n)
                outputf.write(result)

            if i < test_num:
                outputf.write("\n")