# Encoding: utf-8
'''
Created on 12.04.2014

@author: Los

@version: 0.0.1
'''
import sys

def main(argv=None):
    if argv is None:
        argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')
    T = int(input())
     
    for i in range(T):
        cost, flow, goal = map(float, tuple(input().split()))
        min_sec=cost/flow
        rate=2
        bank=0
        sec=0
        flag=True
        while flag:
            t=min((goal-bank)/rate, cost/rate)
            bank+=t*rate
            sec+=t
            if abs(bank-goal)<0.000001:
                case='Case #{0}: {1}'.format(i+1,sec)
                print(case)
                flag=False
            else:
                if (goal-bank)/rate>min_sec:
                    bank-=cost
                    rate+=flow

if __name__ == '__main__':
    main()
