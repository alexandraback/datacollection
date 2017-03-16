temp_res = []
with open("C:/Users/paco/Dropbox/algorithms/google_jam/RevengeofthePancakes/B-small-attempt1.in") as input_file:
    for i, line in enumerate(input_file):
        if i==0:
            n = int(line)
        else:
            temp_res.append(line)
                    
cases = []
for k, val in enumerate(temp_res):
    temp = []
    for char in val:
        if char == '+':
            temp.append(True)
        elif char == '-':
            temp.append(False)
    cases.append((k + 1, temp))

def solve(case):
    stack = case[1][::-1]
    if stack[0]:
        res = 0
    else:
        res = 1
    last_pancake = stack[0]
    for pancake in stack[1:]:
        if last_pancake != pancake:
            res += 1
        last_pancake = pancake
    return res

output_path = "C:/Users/paco/Dropbox/algorithms/google_jam/RevengeofthePancakes/B-small-attempt0.out"

with open(output_path, mode='w') as output:
    for case in cases:
        answer = str(solve(case))
        output.write("Case #{i}: ".format(i=case[0]) + answer + '\n')