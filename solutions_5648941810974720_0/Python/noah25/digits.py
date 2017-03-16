# Google Code Jam 2016 Round 1B
# Problem A. Getting the Digits

# 7, 9.

# Only ZERO contains a Z.
# Only EIGHT contians a G.
# Only TWO contains a W.
# Only SIX contains an X.

# THREE is the only number other that EIGHT that contains an H.
# FOUR is the only number other than ZERO that contains an R.
# FIVE is the only number other than THREE and FOUR that contains an F.
# ONE is the only number other than ZERO, TWO and FOUR that contains an O.
# SEVEN is the only number other than FIVE that contains a V.

def phone(number):
    ZERO = number.count('Z')
    EIGHT = number.count('G')
    TWO = number.count('W')
    SIX = number.count('X')
    THREE = number.count('H') - EIGHT
    FOUR = number.count('R') - (ZERO + THREE)
    FIVE = number.count('F') - FOUR
    ONE = number.count('O') - (ZERO + TWO + FOUR)
    SEVEN = number.count('V') - FIVE
    NINE = (len(number) - (4*ZERO + 3*ONE + 3*TWO + 5*THREE + 4*FOUR + 4*FIVE + 3*SIX + 5*SEVEN + 5*EIGHT))/4
    return (NINE*'9' + EIGHT*'8' + SEVEN*'7' + SIX*'6' + FIVE*'5' + FOUR*'4' + THREE*'3' + TWO*'2' + ONE*'1' + ZERO*'0')[::-1]

def calling():
    f = open('commands.txt', 'r')
    g = open('digits.txt', 'w')
    line = 0
    for i in f:
        if line == 0:
            T = int(i)
            line = 1
        else:
            number = str(i)[:-1]
            g.write('Case #' + str(line) + ': ')
            g.write(phone(number))
            g.write((T != line)*'\n')
            line += 1
    f.close()
    g.close()
