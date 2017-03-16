NUMBERS = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def answer(S):
    S = sorted(S)
    i = 0
    while True:
        phone_number = str(i)
        words = [NUMBERS[int(x)] for x in phone_number]
        letters = sorted([l for w in words for l in w])
        if letters == S:
            return ''.join(sorted(phone_number))
        i += 1

input_file = open('a.txt')
num_cases = int(input_file.readline())
case_num = 1
while case_num <= num_cases:
    S = input_file.readline().strip()
    print "Case #{}: {}".format(case_num, answer(S))
    case_num += 1
