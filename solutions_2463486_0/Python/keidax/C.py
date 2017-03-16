import math


def main():
    fin = open('C-small-attempt0.in')
    fout = open('C-output.txt', 'w')
    num_cases = int(fin.readline().strip())

    for i in range(num_cases):
        output_string = 'Case #'+str(i+1)+": "

        numrange = fin.readline().strip().split()
        fair_and_square = 0
        lower = int(math.ceil(math.sqrt(int(numrange[0]))))
        upper = int(math.floor(math.sqrt(int(numrange[1]))))
        for i in range(lower, upper+1):
            if is_palindrome(i):
                if is_palindrome(i**2):
                    fair_and_square += 1
        fout.write(output_string + str(fair_and_square) + '\n')

    fout.close()
    fin.close()


def is_palindrome(value):
    string = str(value)
    for i in range(0, len(string)/2+1):
        if string[i:i+1] != string[len(string)-i-1:len(string)-i]:
            return False
    return True


def test():
    for i in range(1, 10**7):
        if is_palindrome(i):
                if is_palindrome(i**2):
                    # fair_and_square += 1
                    print i, ",", i**2

if __name__ == '__main__':
    main()
    # test()
