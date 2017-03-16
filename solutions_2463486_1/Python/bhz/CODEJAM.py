in_file = open('DATA.TXT')

MAXH = 100 #change to 100 for large set

# get cases
in_arr = in_file.read().split('\n')
num_cases = int(in_arr[0])
case_arr = in_arr[1:]
out = []
num = 0

BIGARR = [int(e) for e in open('DATA2.TXT').read().split('\n')[:-1]]

for case in case_arr:
    res = 0
    try: int_case = [int(e) for e in case.split(' ')]
    except: int_case = [0, 0]
    for e in BIGARR:
        if int_case[0] <= e <= int_case[1]: res += 1
    num += 1
    if num % 1000 == 0: print num
    out.append('Case #' + str(num) + ': ' + str(res))

f = open('DATA2.txt', 'w')
for e in out:
    f.write(str(e) + '\n')
f.close()
