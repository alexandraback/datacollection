temp_res = []
with open("C:/Users/paco/Dropbox/algorithms/google_jam/Fractiles/A-large.in") as input_file:
    for i, line in enumerate(input_file):
        if i==0:
            n = int(line)
        else:
            temp_res.append([int(val) for val in line.split(" ")])

cases = []
for i, val in enumerate(temp_res):
    k, c, s = val
    cases.append((i + 1, k, c, s))

def get_students(k, c):
    digits = []
    students = []
    for j in range(k):
        digits.append(j)
        if j%c == c - 1:
            students.append(get_student_place(digits, k))
            digits = []
    if k%c == 0:
        return students
    digits += [0] * (c - len(digits))
    students.append(get_student_place(digits, k))
    return students    

def get_student_place(digits, base):
    place = 1
    for i, digit in enumerate(digits):
        place += digit * base**(len(digits) - 1 - i)
    return place
    
def solve(case):
    _, k, c, s = case
    if k == 1:
        if s < 1:
            return 'IMPOSSIBLE'
        else:
            return "1"
    if c == 1:
        if s < k:
            return 'IMPOSSIBLE'
        else:
            return ' '.join([str(val) for val in range(1, k+1)])
    if k % c == 0 and s < int(k / c):
        return 'IMPOSSIBLE'
    if k % c == 0:
        return ' '.join([str(val) for val in get_students(k, c)])
    if s <= int(k / c):
        return 'IMPOSSIBLE'
    else:
        return ' '.join([str(val) for val in get_students(k, c)])
    
output_path = "C:/Users/paco/Dropbox/algorithms/google_jam/Fractiles/D-small-attempt0.out"

with open(output_path, mode='w') as output:
    for case in cases:
        answer = solve(case)
        output.write("Case #{i}: ".format(i=case[0]) + answer + '\n')