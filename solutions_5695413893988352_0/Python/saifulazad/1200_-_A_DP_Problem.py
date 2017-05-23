__author__ = 'Azad'
import re

def calculate(p):

    val_x = re.findall('(-?\+?)(\d+)(x)?',p)

    const = [x[0]+x[1] for x in val_x if x[2]=='']

    tottal_const = sum([int(x) for x in const])

    #print(const)
    val_x = re.findall('\+?-?\d*x',p)
    #print(val_x)
    without_x = [ x.replace('x','1') if x  in ['+x','-x','x'] else x.replace('x','') for x in val_x ]
    #print(without_x)

    r  = sum([int(x) for x in without_x])

   #
    return (r,tottal_const)


def process_input():


    p = input()

    ls = calculate(p.split('=')[0])

    rs  = calculate(p.split('=')[1])

    x_val = ls[0] - rs[0]
    #print(x_val)
    con_val = -ls[1] + rs[1]

    if x_val == 0 :
        if con_val ==0:
            print('IDENTITY')
        else:
            print('IMPOSSIBLE')
    else:
        print(con_val//x_val)


case = int(input())

for x in range(case):
    process_input()