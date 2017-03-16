#!/usr/bin/env python
import sys
import logging

def main():
    import argparse
    parser = argparse.ArgumentParser(description='')
    parser.add_argument('input_file',help='The program\'s input file.')
    parser.add_argument('-o','--outfile',required=False,help='The program\'s output file.')
    parser.add_argument('-d','--debug',help='Debug logging level',action="store_true")
    
    args = parser.parse_args()

    if args.debug:
        logging.basicConfig(level=logging.DEBUG)

    f = open(args.input_file,'r')
    fout = sys.stdout
    if args.outfile:
        fout = open(args.outfile,'w')

    cases = int(f.readline())

    for case_number in range(cases):
        logging.debug('Case %d',case_number+1)
        ht,wid = [int(c) for c in f.readline().split()]
        lawn = {}
        for j in range(ht):
            row = f.readline().split()
            for i in range(wid):
                lawn[(i,j)]=int(row[i])

        phrase = 'YES'
        while True: 
            try:
                lowest = min(lawn.iteritems(),key=lambda x: x[1])
            except ValueError:
                break

            h_status = check_horizontal(lawn,lowest)
            v_status = check_vertical(lawn,lowest)

            if h_status or v_status:
                continue

            phrase = 'NO'
            break
            
        print >>fout,'Case #%d: %s'%(case_number+1,phrase)

def check_horizontal(lawn,item):
    h = item[1]
    strip = [k for k in lawn.iterkeys() if k[1]==item[0][1]]
    for t in strip:
        hcmp = lawn[t]
        if hcmp>h:
            return False

    for t in strip:
        del lawn[t]

    return True

def check_vertical(lawn,item):
    h = item[1]
    strip = [k for k in lawn.iterkeys() if k[0]==item[0][0]]
    for t in strip:
        hcmp = lawn[t]
        if hcmp>h:
            return False

    for t in strip:
        del lawn[t]

    return True

if __name__=='__main__':
    main()
