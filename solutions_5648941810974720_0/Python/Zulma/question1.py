

if __name__ == '__main__':
    T = int(raw_input())
    index = 1
    for _ in range(T):
        occurences = [0] * 10
        number = list(raw_input())

        # search Z
        occurences[0] = number.count('Z')

        for _ in range(occurences[0]):
            number.remove('Z')
            number.remove('E')
            number.remove('R')
            number.remove('O')

        # seqrch W
        occurences[2] = number.count('W')
        for _ in range(occurences[2]):
            number.remove('T')
            number.remove('W')
            number.remove('O')

        # seqrch U
        occurences[4] = number.count('U')
        for _ in range(occurences[4]):
            number.remove('F')
            number.remove('O')
            number.remove('U')
            number.remove('R')

        # seqrch X
        occurences[6] = number.count('X')
        for _ in range(occurences[6]):
            number.remove('S')
            number.remove('I')
            number.remove('X')

        # seqrch G
        occurences[8] = number.count('G')
        for _ in range(occurences[8]):
            number.remove('E')
            number.remove('I')
            number.remove('G')
            number.remove('H')
            number.remove('T')

        # seqrch H
        occurences[3] = number.count('H')
        for _ in range(occurences[3]):
            number.remove('T')
            number.remove('H')
            number.remove('R')
            number.remove('E')
            number.remove('E')

        # seqrch F
        occurences[5] = number.count('F')
        for _ in range(occurences[5]):
            number.remove('F')
            number.remove('I')
            number.remove('V')
            number.remove('E')

        # seqrch V
        occurences[7] = number.count('V')
        for _ in range(occurences[7]):
            number.remove('S')
            number.remove('E')
            number.remove('V')
            number.remove('E')
            number.remove('N')

        # seqrch O
        occurences[1] = number.count('O')
        for _ in range(occurences[1]):
            number.remove('O')
            number.remove('N')
            number.remove('E')

        # seqrch I
        occurences[9] = number.count('I')
        for _ in range(occurences[9]):
            number.remove('N')
            number.remove('I')
            number.remove('N')
            number.remove('E')
        output = ""
        for i in range(10):
            for _ in range(occurences[i]):
                output = output + str(i)

        print "Case #{}: {}".format(index, output)
        index = index + 1
