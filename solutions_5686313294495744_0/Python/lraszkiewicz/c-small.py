from math import pow

T = int(input())
for t in range(0, T):
    n = int(input())
    lines = []
    for i in range(0, n):
        lines.append(input())
    result = 0
    format_str = '0' + str(n) + 'b'
    for i in range(0, int(pow(2, n))):
        is_fake = format(i, format_str)
        first_words = []
        second_words = []
        for j in range(0, n):
            if is_fake[j] == '0':
                first_words.append(lines[j].split()[0])
                second_words.append(lines[j].split()[1])
        is_correct_solution = 1
        for j in range(0, n):
            if is_fake[j] == '1':
                if not ((lines[j].split()[0] in first_words) and
                        (lines[j].split()[1] in second_words)):
                    is_correct_solution = 0
                    break
        if is_correct_solution == 1:
            result = max(result, is_fake.count('1'))
    print("Case #" + str(t+1) + ": " + str(result))
