from sys import stdin

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args


result = ''


def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        global result
        result = ''

        letters = stdin.readline()
        l_map = {}
        important_letters = set(['Z', 'W', 'U', 'X', 'G', 'O', 'F', 'T', 'S', 'I'])
        for letter in letters:
            if letter in important_letters:
                if letter not in l_map:
                    l_map[letter] = 1
                else:
                    l_map[letter] += 1

        def sub_map(word, times):
            if times == 0:
                return
            for letter in word:
                if letter in l_map:
                    l_map[letter] -= times

        def do_num(letter, word, int_num):
            global result

            if letter not in l_map:
                return
            num_nums = l_map[letter]
            sub_map(word, l_map[letter])
            result += str(int_num) * num_nums

        do_num('Z', 'ZERO', 0)
        do_num('W', 'TWO', 2)
        do_num('U', 'FOUR', 4)
        do_num('X', 'SIX', 6)
        do_num('G', 'EIGHT', 8)
        do_num('O', 'ONE', 1)
        do_num('F', 'FIVE', 5)
        do_num('T', 'THREE', 3)
        do_num('S', 'SEVEN', 7)
        do_num('I', 'NINE', 9)

        import string
        result = string.join(sorted(result), '')

        print "Case #{}: {}".format(case, result)


if __name__ == "__main__":
    main()
