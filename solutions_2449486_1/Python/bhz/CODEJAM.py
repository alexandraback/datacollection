in_file = open('DATA.TXT')

MAXH = 100 #change to 101 for large set

# get cases
in_arr = in_file.read().split('\n')
num_cases = int(in_arr[0])
case_arr = []
row = 1
for e in range(num_cases):
    case_len = int(in_arr[row].split(' ')[0]) + 1
    case_arr.append(in_arr[row:row+case_len])
    row += case_len
out = []
num = 0

for case in case_arr:
    res = 'YES'
    rows = int(case[0].split(' ')[0])
    cols = int(case[0].split(' ')[1])
    case_ = case[1:]
    # convert to integers
    int_case = [[int(i) for i in e.split(' ')] for e in case_]
    for h in range(1, MAXH):
        bool_case = [[i > h for i in e] for e in int_case]
        tries = [[True for i in e] for e in int_case]
        # trim rows
        for e in range(rows):
            canTrim = True
            for i in bool_case[e]:
                if i:
                    canTrim = False;
                    break;
            if canTrim: tries[e] = [False] * len(tries[0])
        # trim cols
        for e in range(cols):
            canTrim = True
            for i in range(rows):
                if bool_case[i][e]:
                    canTrim = False;
                    break;
            if canTrim:
                for i in range(rows): tries[i][e] = False;
        if bool_case != tries:
            res = 'NO'
            break
    
    num += 1
    out.append('Case #' + str(num) + ': ' + res)

for e in out: print e
