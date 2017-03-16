from collections import Counter


def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "FAIL"
    outputLine = casestr+status
    print outputLine


def main():
    T = int( raw_input() )

    for t in xrange(T):    
        letters = raw_input()
        c = Counter(letters)
        ltr0 = c['Z']
        if ltr0 > 0:
            c['Z'] -= ltr0
            c['E'] -= ltr0
            c['R'] -= ltr0
            c['O'] -= ltr0

        ltr2 = c['W']
        if ltr2 > 0:
            c['T'] -= ltr2
            c['W'] -= ltr2
            c['O'] -= ltr2

        ltr4 = c['U']
        if ltr4 > 0:
            c['F'] -= ltr4
            c['O'] -= ltr4
            c['U'] -= ltr4
            c['R'] -= ltr4

        ltr6 = c['X']
        if ltr6 > 0:
            c['S'] -= ltr6
            c['I'] -= ltr6
            c['X'] -= ltr6

        ltr8 = c['G']
        if ltr8 > 0:
            c['E'] -= ltr8
            c['I'] -= ltr8
            c['G'] -= ltr8
            c['H'] -= ltr8
            c['T'] -= ltr8

        ltr3 = c['H']
        if ltr3 > 0:
            c['T'] -= ltr3
            c['H'] -= ltr3
            c['R'] -= ltr3
            c['E'] -= ltr3*2

        ltr1 = c['O']
        if ltr1 > 0:
            c['O'] -= ltr1
            c['N'] -= ltr1
            c['E'] -= ltr1

        ltr5 = c['F']
        if ltr5 > 0:
            c['F'] -= ltr5
            c['I'] -= ltr5
            c['V'] -= ltr5
            c['E'] -= ltr5

        ltr7 = c['S']
        if ltr7 > 0:
            c['S'] -= ltr7
            c['E'] -= ltr7*2
            c['V'] -= ltr7
            c['N'] -= ltr7

        ltr9 = c['I']

        tel = '0'*ltr0 + '1'*ltr1 + '2'*ltr2 + '3'*ltr3 + '4'*ltr4 + '5'*ltr5 + '6'*ltr6 + '7'*ltr7 + '8'*ltr8 + '9'*ltr9

        output(t, tel)

if __name__ == "__main__":
   main()