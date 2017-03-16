__author__ = 'Orin'

def check_ship(row = 1, col = 2, w = 1):
    times = 0
    times = col / w
    times *= row
    times += w
    if col % w == 0:
        times -= 1
    return times


def main():
    folder_path = 'C:\\Users\\Orin_2\\Projects\\CodeJam\\2015\\Round1C\\'
    in_name = 'A-large.in'
    out_name = 'A-large.out'

    with open(folder_path + in_name,'r') as inp:
        cases = inp.read().split('\n')
        for i in range(len(cases)):
            cases[i] = cases[i].split(' ')
    if cases[len(cases)-1] == '':
        cases.remove("")

    for c in range(len(cases)):
        for i in range(len(cases[c])):
            cases[c][i]  = int(cases[c][i])

    t = cases[0][0]
    cases.remove([t])

    with open(folder_path + out_name,'w') as out:
        for case in range(t):
            row = cases[case][0]
            col = cases[case][1]
            w = cases[case][2]

            times = check_ship(row, col, w)

            out.write("Case #{0}: {1}\n".format(case+1,times))

if __name__ == '__main__':
    main()