# python 3
import string
import itertools
import sys

def dig(avol, atyp, bvol, btyp,
        aidx, aleft, bidx, bleft):
    if atyp[aidx] == btyp[bidx]:
        vol = min(aleft, bleft)
    else:
        vol = 0
    ext = 0
    if aidx+1 < len(avol):
        ext = max(ext, dig(avol, atyp, bvol, btyp,
                           aidx+1, avol[aidx+1],
                           bidx, bleft-vol))
    if bidx+1 < len(bvol):
        ext = max(ext, dig(avol, atyp, bvol, btyp,
                           aidx, aleft-vol,
                           bidx+1, bvol[bidx+1]))
    result = vol + ext
    return result

def process_case(avol, atyp, bvol, btyp):
    result = dig(avol, atyp, bvol, btyp,
                 0, avol[0], 0, bvol[0])
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        an,bn = line_of_numbers(next(lines))
        adata = line_of_numbers(next(lines))
        bdata = line_of_numbers(next(lines))
        avol = adata[0::2]
        atyp = adata[1::2]
        bvol = bdata[0::2]
        btyp = bdata[1::2]
        result = process_case(avol, atyp, bvol, btyp)
        yield 'Case #{0}: {1}\n'.format(ci, result)
    
def line_of_numbers(s):
    return [int(sub) for sub in s.split()]

def input_gen(f_in):
    for line in f_in:
        if line.endswith('\n'):
            line = line[:-1]
        yield line

def start(basename):
    infile = basename + '.in'
    outfile = basename + '.out'
    f_in = open(infile, 'r')
    f_out = open(outfile, 'w')
    f_out.writelines(result_gen(input_gen(f_in)))
    f_in.close()
    f_out.close()

##start('C-test')
start('C-small-attempt0')
##start('C-large')
