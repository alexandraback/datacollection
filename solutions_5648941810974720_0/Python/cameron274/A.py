def remove_letters(s, letters):
    for i in letters:
        s.remove(i)

def run_test():
    s = list(raw_input())
    digits = list()
    while (s.count("Z") != 0):
        remove_letters(s, "ZERO")
        digits.append(0)
    while (s.count("W") != 0):
        remove_letters(s, "TWO")
        digits.append(2)
    while (s.count("X") != 0):
        remove_letters(s, "SIX")
        digits.append(6)
    while (s.count("G") != 0):
        remove_letters(s, "EIGHT")
        digits.append(8)
    while (s.count("H") != 0):
        remove_letters(s, "THREE")
        digits.append(3)
    while (s.count("R") != 0):
        remove_letters(s, "FOUR")
        digits.append(4)
    while (s.count("F") != 0):
        remove_letters(s, "FIVE")
        digits.append(5)
    while (s.count("V") != 0):
        remove_letters(s, "SEVEN")
        digits.append(7)
    while (s.count("O") != 0):
        remove_letters(s, "ONE")
        digits.append(1)
    while (s.count("I") != 0):
        remove_letters(s, "NINE")
        digits.append(9)
    digits.sort()
    result = ""
    for i in digits:
        result = result + str(i)
    return result

t = int(raw_input())
for i in range(1, t+1):
    print("Case #%d: %s" % (i, run_test()))