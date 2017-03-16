from string import *

x = int(input(""))

for j in range(1,x+1):
    string = input("")

    #print(string)

    alphabet = {c:0 for c in ascii_uppercase}
    for s in string: alphabet[s] += 1
    numbers = {x:0 for x in range(0,10)}

    # Take away all zeroes
    numbers[0] = alphabet['Z']
    alphabet['Z'] -= numbers[0]
    alphabet['E'] -= numbers[0]
    alphabet['R'] -= numbers[0]
    alphabet['O'] -= numbers[0]

    # Take away all eights
    numbers[8] = alphabet['G']
    alphabet['E'] -= numbers[8]
    alphabet['I'] -= numbers[8]
    alphabet['G'] -= numbers[8]
    alphabet['H'] -= numbers[8]
    alphabet['T'] -= numbers[8]

    # Take away all sixes
    numbers[6] = alphabet['X']
    alphabet['S'] -= numbers[6]
    alphabet['I'] -= numbers[6]
    alphabet['X'] -= numbers[6]

    # Take away all threes
    numbers[3] = alphabet['H']
    alphabet['T'] -= numbers[3]
    alphabet['H'] -= numbers[3]
    alphabet['R'] -= numbers[3]
    alphabet['E'] -= numbers[3]
    alphabet['E'] -= numbers[3]

    # Take away all fours
    numbers[4] = alphabet['R']
    alphabet['F'] -= numbers[4]
    alphabet['O'] -= numbers[4]
    alphabet['U'] -= numbers[4]
    alphabet['R'] -= numbers[4]

    # Take away all fives
    numbers[5] = alphabet['F']
    alphabet['F'] -= numbers[5]
    alphabet['I'] -= numbers[5]
    alphabet['V'] -= numbers[5]
    alphabet['E'] -= numbers[5]

    # Take away all twos
    numbers[2] = alphabet['W']
    alphabet['T'] -= numbers[2]
    alphabet['W'] -= numbers[2]
    alphabet['O'] -= numbers[2]

    # Take away all ones
    numbers[1] = alphabet['O']
    alphabet['O'] -= numbers[1]
    alphabet['N'] -= numbers[1]
    alphabet['E'] -= numbers[1]

    # Take away all sevens
    numbers[7] = alphabet['V']
    alphabet['S'] -= numbers[7]
    alphabet['E'] -= numbers[7]
    alphabet['V'] -= numbers[7]
    alphabet['E'] -= numbers[7]
    alphabet['N'] -= numbers[7]

    # Take away all nines
    numbers[9] = alphabet['N'] // 2
    alphabet['N'] -= numbers[9]
    alphabet['I'] -= numbers[9]
    alphabet['N'] -= numbers[9]
    alphabet['E'] -= numbers[9]

    #for i in ascii_uppercase:
    #    print(i + " " + str(alphabet[i]))

    num_list = []
    for i in range(0,10):
        num_list.append(str(i)*numbers[i])
    phone_number = "".join(num_list)
    print("Case #%d: %s" % (j,phone_number))