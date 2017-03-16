# Language       : Python 3
# Compiled Using : py_compile
# Version        : Python 3.4.3


def remove_letter(word, l):
    new_word = ""
    first_occ = True
    for w in word:
        if w == l and first_occ:
            first_occ = False
        else:
            new_word += w

    assert(first_occ == False)
    return new_word


def count_letter(word, l):
    count = 0
    for w in word:
        if w == l:
            count += 1
    return count



with open("A-small-attempt0.in") as f:
    data = f.readlines()

first = True
test_case_counter = 0
for line in data:
    if first:
        first = False;
        continue
    # Get rid of the \n at the end.
    line = line[:-1]
    test_case_counter += 1
    numbers = []
    count = count_letter(line, "Z")
    for c in range(count):
        numbers.append(0)
        for l in "ZERO":
            line = remove_letter(line, l)
    count = count_letter(line, "X")
    for c in range(count):
        numbers.append(6)
        for l in "SIX":
            line = remove_letter(line, l)
    count = count_letter(line, "G")
    for c in range(count):
        numbers.append(8)
        for l in "EIGHT":
            line = remove_letter(line, l)
    count = count_letter(line, "H")
    for c in range(count):
        numbers.append(3)
        for l in "THREE":
            line = remove_letter(line, l)
    count = count_letter(line, "W")
    for c in range(count):
        numbers.append(2)
        for l in "TWO":
            line = remove_letter(line, l)
    count = count_letter(line, "R")
    for c in range(count):
        numbers.append(4)
        for l in "FOUR":
            line = remove_letter(line, l)
    count = count_letter(line, "S")
    for c in range(count):
        numbers.append(7)
        for l in "SEVEN":
            line = remove_letter(line, l)
    count = count_letter(line, "O")
    for c in range(count):
        numbers.append(1)
        for l in "ONE":
            line = remove_letter(line, l)
    count = count_letter(line, "F")
    for c in range(count):
        numbers.append(5)
        for l in "FIVE":
            line = remove_letter(line, l)
    count = count_letter(line, "E")
    for c in range(count):
        numbers.append(9)
        for l in "NINE":
            line = remove_letter(line, l)
    assert(len(line) == 0)
    numbers = sorted(numbers)
    result = ""
    for n in numbers:
        result += str(n)
    print("Case #" + str(test_case_counter) + ": " + str(result))
