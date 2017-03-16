def splitter(number):
    s = str(number)
    return int(s[:len(s)//2] or "0"), int(s[len(s)//2:]), len(s[len(s)//2:])


def compute(number):
    steps = 0

    while number:
        # get second part of the number
        half1, half2, l = splitter(number)

        if half2 == 0:
            steps += 1
            number -= 1
            half1, half2, l = splitter(number)

        steps += half2 - 1
        number -= half2 -1

        number = half1 * 10**l + 1
        if number == 1:
            return steps + 1

        # switch
        if str(number) != str(number)[::-1]:

            number = int(str(number)[::-1])
            steps += 1


        mi = int(str(number)[1:] or str(number))
        number -= mi
        steps += mi




def read_number(f):
    return int(f.readline().strip())

def main():
    with open('A-small-attempt1.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            number = read_number(f)
            #print(number)
            print('Case #{}: {}'.format(test_case + 1, compute(number)))

if __name__ == '__main__':
    main()