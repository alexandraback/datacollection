temp_res = []
with open("C:/Users/paco/Dropbox/algorithms/google_jam/CountingSheep/A-small-attempt0.in") as input_file:
    for i, line in enumerate(input_file):
        if i==0:
            n = int(line)
        else:
            temp_res.append(int(line))

cases = []
for k, val in enumerate(temp_res):
    cases.append((k + 1, val))

def get_digits(k, memory):
    if k in memory:
        return memory[k]
    else:
        memory[k] = [int(k%10)] + get_digits(int(k/10), memory)
        return memory[k]

def solve(case, memory):
    selected_number = case[1]
    if selected_number == 0:
        return 'INSOMNIA'
    else:
        seen_digits = set()
        k = 0
        while(len(seen_digits) != 10):
            k += selected_number
            for digit in get_digits(k, memory):
                seen_digits.add(digit)
        return str(k)    
    
output_path = "C:/Users/paco/Dropbox/algorithms/google_jam/CountingSheep/A-small-attempt0.out"
with open(output_path, mode='w') as output:
    memory = dict()
    for i in range(10):
        memory[i] = [i]
    for case in cases:
        answer = solve(case, memory)
        output.write("Case #{i}: ".format(i=case[0]) + answer + '\n')