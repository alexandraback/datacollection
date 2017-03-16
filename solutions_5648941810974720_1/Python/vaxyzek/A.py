import gcj, numpy.linalg

letters = "EGFIHONSRUTWVXZ"
digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

#digits = ["ONE", "THREE", "FIVE", "SEVEN", "NINE"]

#digits = ["THREE", "FIVE", "SEVEN", "NINE"]

#digits = ["FIVE", "SEVEN", "NINE"]

#digits = ["SEVEN", "NINE"]

#z where ZERO
#W where TWO
#U where four
#x where SIX
#g where eight 


#o where ones

ifile, ofile = gcj.get_files('A')

T = int(ifile.readline().strip())
for t in range(T):
    s = ifile.readline().strip()
    N = len(letters)

    b = [0] * N

    for l in s:
        ix = letters.find(l)
        b[ix] += 1

    A = [[0] * N for i in range(10)]

    for i in range(10):
        digit = digits[i]
        for l in digit:
            ix = letters.find(l)
            A[i][ix] += 1

    zeroes = b[14]
    for i in range(N):
        b[i] -= zeroes * A[0][i]

    #print(zeroes, b)
    twoes  = b[11]
    for i in range(N):
        b[i] -= twoes * A[2][i]

    #print(twoes, b)
    fours  = b[9]
    for i in range(N):
        b[i] -= fours * A[4][i]
    
    #print(fours, b)
    sixes  = b[13]
    for i in range(N):
        b[i] -= sixes * A[6][i]

    #print(eights, b)
    eights = b[1]
    for i in range(N):
        b[i] -= eights * A[8][i]

    ones = b[5]
    for i in range(N):
        b[i] -= ones * A[1][i]

    threes = b[4]
    for i in range(N):
        b[i] -= threes * A[3][i]

    fives = b[2]
    for i in range(N):
        b[i] -= fives * A[5][i]

    sevens = b[7]
    for i in range(N):
        b[i] -= sevens * A[7][i]

    #print(b)
    nines = b[0]

    gcj.print_answer(ofile, t, ("0" * zeroes) + ("1" * ones) + "2" * twoes + "3" * threes + "4" * fours + "5" * fives + "6" * sixes + "7" * sevens + "8" * eights + "9" * nines)