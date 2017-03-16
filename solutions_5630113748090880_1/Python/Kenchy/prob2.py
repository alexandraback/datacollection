__author__ = 'ligenjian'

if __name__ == '__main__':
    input = open('input.txt', 'r')
    output = open('output.txt', 'w')
    t = int(input.readline())
    for i in range(t):
        total_number = {}
        n = int(input.readline())
        for line in range(2 * n - 1):
            numbers = map(int, input.readline().strip().split(' '))
            for number in numbers:
                total_number.setdefault(number, False)
                total_number[number] = not total_number[number]
        result = sorted(map(lambda x: x[0], filter(lambda (k,v): v,total_number.items())))
        print>>output,  'Case #%d: %s' % ((i + 1), ' '.join(map(str, result)))
