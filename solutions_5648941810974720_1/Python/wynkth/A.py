with open('A-large.in', 'rb') as f:
    lines = map(lambda x: x.replace('\n',''), f.readlines())

with open('outA.txt', 'wb') as out:
    for case, number in enumerate(lines):
        if case != 0:
            letters = []
            numbers = []
            for n in list(number):
                letters.append(n)
            for n in [('ZERO', 0), ('TWO', 2), ('SIX', 6), ('SEVEN', 7), ('EIGHT', 8),
                      ('FOUR', 4), ('FIVE', 5), ('NINE', 9), ('ONE', 1), ('THREE', 3)]:
                while all(n[0].count(x) <= letters.count(x) for x in list(n[0])):
                    numbers.append(n[1])
                    for x in n[0]:
                        letters.remove(x)

            numbers = sorted(map(str, numbers))
            out.write('Case #' + str(case) + ': ' + ''.join(numbers) + '\n')


