def input():
    with open('b.in') as file:
        lines_count = int(file.readline().strip())
        for i in xrange(lines_count):
            line = file.readline().strip()
            yield tuple(int(d) for d in line.split())

def output(answers):
    with open('b.out', 'w') as file:
        for i, answer in enumerate(answers):
            file.write('Case #%s: %s\n' % (i + 1, answer))

def solve(surprises_count, good_result, results):
    kickass_dancers_count = 0
    for result in results:
        residue = result % 3
        average = result / 3
        if residue == 0:
            if average >= good_result:
                kickass_dancers_count += 1
            elif average + 1 == good_result and surprises_count and average not in (0, 10):
                kickass_dancers_count += 1
                surprises_count -= 1
        elif residue == 1:
            if average + 1 >= good_result:
                kickass_dancers_count += 1
        elif residue == 2:
            if average + 1 >= good_result:
                kickass_dancers_count += 1
            elif average + 2 == good_result and surprises_count and average != 9:
                kickass_dancers_count += 1
                surprises_count -= 1
    return kickass_dancers_count

def main():
    answers = []
    for task in input():
        dancers_count = task[0]
        surprises_count = task[1]
        good_result = task[2]
        results = [task[3 + i] for i in xrange(dancers_count)]

        answers.append(solve(surprises_count, good_result, results))

    output(answers)

if __name__ == '__main__':
    main()