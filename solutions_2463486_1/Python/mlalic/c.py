from __future__ import division, print_function


def generate(num):
    cnt = 0
    num = str(num)
    length = len(num)
    digit = 0
    first_list = []
    while True:
        new_num = int(''.join([num[:length // 2],
                              str(digit),
                              num[length // 2:]]))
        square = str(new_num ** 2)
        valid = square == square[::-1]
        if not valid:
            break
        else:
            first_list.append(new_num)
            cnt += 1
        digit += 1

    digit = 0
    l = []
    while True:
        new_num = int(''.join([num[:length // 2],
                              str(digit) * 2,
                              num[length // 2:]]))
        square = str(new_num ** 2)
        valid = square == square[::-1]
        if not valid:
            break
        else:
            l.append(new_num)
            cnt += 1
        digit += 1

    return first_list, l, cnt


def main():
    total_count = 2
    cutoff = 55
    all_numbers = [1, 2, 3, 11, 22]
    l = [11, 22]
    while True:
        if len(str(l[0])) >= cutoff:
            break
        new_l = []
        for i in l:
            q, a, c = generate(i)
            all_numbers.extend(q)
            all_numbers.extend(a)
            total_count += c
            new_l.extend(a)
        l = new_l

    maximum = 10 ** 100
    all_numbers = [i ** 2 for i in all_numbers if i ** 2 <= maximum]
    all_numbers.sort()

    with open('c.in', 'r') as f:
        first = True
        for case_number, line in enumerate(f):
            if first:
                first = False
                continue
            a, b = map(int, line.split())

            ans = 0
            for i in all_numbers:
                if i < a:
                    continue
                if i <= b:
                    ans += 1
                else:
                    break
            print('Case #%d: %d' % (case_number, ans))


if __name__ == '__main__':
    main()
