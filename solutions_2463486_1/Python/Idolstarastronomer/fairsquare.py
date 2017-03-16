#!/usr/bin/env python
import sys
import logging
import itertools

def main():
    import argparse
    parser = argparse.ArgumentParser(description='')
    parser.add_argument('input_file',help='The program\'s input file.')
    parser.add_argument('-o','--outfile',required=False,help='The program\'s output file.')
    parser.add_argument('-d','--debug',help='Debug logging level',action="store_true")
    
    args = parser.parse_args()

    if args.debug:
        logging.basicConfig(level=logging.DEBUG)

    fsq_list = list(fair_squares(14))

    f = open(args.input_file,'r')
    fout = sys.stdout
    if args.outfile:
        fout = open(args.outfile,'w')

    cases = int(f.readline())

    for case_number in range(cases):
        logging.debug('Case %d',case_number+1)
        low,high = [long(i) for i in f.readline().split()]
        matching = [i for i in fsq_list if i>=low and i<=high]

        print >>fout,'Case #%d: %d'%(case_number+1,len(matching))
   
    fsq_list.sort()
    logging.debug('List: %s',repr(fsq_list))

def fair_squares(max_digits):
    max_fairs = max_digits/2
    if max_digits%2 == 1:
        max_fairs+=1
    for i in fairs(max_fairs):
        square = i*i
        seq = list(str(square))
        revseq = list(seq)
        revseq.reverse()
        if seq == revseq:
            logging.debug('Found %d (root: %d) (length=%d)',square,i,len(str(square)))
            yield square
        i+=1L

def fairs(max_digits):
    digits = [str(i) for i in range(10)]

    for d in range(1,max_digits+1):
        prod_repeat = d/2
        if d%2==1:
            prod_repeat+=1
            crop_left = True
        else:
            crop_left = False

        for rh_part in itertools.product(digits,repeat=prod_repeat):
            if rh_part[-1]=='0':
                continue

            rh_list = list(rh_part)
            lh_part = list(rh_part)
            lh_part.reverse()
            if crop_left:
                lh_part = lh_part[:-1]
            yield long(''.join(lh_part+rh_list))

if __name__=='__main__':
    main()
