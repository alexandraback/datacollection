def input():
    with open('c.in') as file:
        lines_count = int(file.readline().strip())
        for i in xrange(lines_count):
            line = file.readline().strip()
            yield tuple(int(d) for d in line.split())

def output(answers):
    with open('c.out', 'w') as file:
        for i, answer in enumerate(answers):
            file.write('Case #%s: %s\n' % (i + 1, answer))

def cycle(number):
    pairs = {number}
    string = str(number)
    for steps in xrange(len(string)):
        paired_string = string[steps:] + string[:steps]
        if not paired_string.startswith('0'):
            paired_number = int(paired_string)
            if paired_number > number and paired_number not in pairs:
                pairs.add(paired_number)
                yield paired_number

def solve(a, b):
    pairs_count = 0
    for n in xrange(a, b):
        for m in cycle(n):
            if m <= b:
                pairs_count += 1
    return pairs_count

def main():
    answers = []
    for task in input():
        answers.append(solve(*task))

    output(answers)

if __name__ == '__main__':
    main()