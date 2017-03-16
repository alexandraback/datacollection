
in_file = "A-large.in"
out_file = "elf.out"

out = open(out_file, 'w')

def calGenerator(P, Q):
    generation_count = 1
    if Q % 2 != 0:
        return "impossible"
    Q /= 2
    while Q > P:
        if Q % 2 != 0:
            return "impossible"
        Q /= 2
        generation_count += 1
    if P - Q != 0:
        result = calGenerator(P - Q, Q)
        if result == "impossible":
            return "impossible"
        elif generation_count + result > 40:
            return "impossible"

    return generation_count



def result_out(case, result):
    out.write("Case #" + str(case) + ": " + str(result) + '\n')


with open(in_file) as f:
    case_num = int(f.readline())
    for case in range(1, case_num + 1):
        numbers = f.readline().strip().split('/')
        P = int(numbers[0])
        Q = int(numbers[1])
        result = calGenerator(P, Q)
        result_out(case, result)



