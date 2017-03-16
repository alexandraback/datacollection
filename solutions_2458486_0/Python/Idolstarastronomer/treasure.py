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
        nkeys,nchests = [int(c) for c in f.readline().split()]
        logging.debug('#Keys: %d, #Chests: %d', nkeys, nchests)
        keys = [int(c) for c in f.readline().split()]
        logging.debug('Starting Keys: %s',repr(keys))
        chests = []
        for i in range(nchests):
            chest_args = [int(c) for c in f.readline().split()]
            chests.append(Chest(i+1,chest_args[0],chest_args[2:]))
            logging.debug('Chest %d: Lock: %d Keys inside: %s',chests[-1].number,chests[-1].lock,repr(chests[-1].keys))

        #chests.sort()
        #chests.reverse()

        result = go_deeper(keys,chests,[])

        if result:
            phrase = ' '.join([str(i) for i in result])
        else:
            phrase = 'IMPOSSIBLE'

        print >>fout,'Case #%d: %s'%(case_number+1,phrase)
        logging.debug("Sequence: %s",phrase)

class Chest(object):
    def __init__(self,number,lock,keys):
        self.number = number
        self.lock = lock
        self.keys = keys


def go_deeper(keys,chests,opened):
    if not chests:
        return opened # Sequence found
    if not keys:
        return False # No more keys
    if not look_ahead_check(keys,chests):
        return False # Abandon branch, not enough keys left to open remining chests

    logging.debug('Open: %s',repr(opened))
    for c in chests:
        if c.lock in keys:
            remain_chests = list(chests)
            remain_chests.remove(c)
            remain_keys = list(keys)
            remain_keys.remove(c.lock)
            remain_keys.extend(c.keys)
            new_opened = list(opened)
            new_opened.append(c.number)
            retval = go_deeper(remain_keys,remain_chests,new_opened)
            if retval:
                return retval

    return False

def look_ahead_check(start_keys,chests):
    """Is it still possible to open the remaining chests?"""
    locks = {}
    keys = {}
    for k in start_keys:
        if k in keys:
            keys[k]+=1
        else:
            keys[k]=1

    for c in chests:
        for k in c.keys:
            if k in keys:
                keys[k]+=1
            else:
                keys[k]=1

        if c.lock in locks:
            locks[c.lock].append(c)
        else:
            locks[c.lock]=[c]

    for l,chests_l in locks.iteritems():
        nchests = len(chests_l)
        try:
            nkeys = keys[l]
        except KeyError:
            return False # No keys for this lock are available

        if nchests>nkeys:
            return False # Not enough keys left

        trapped_key_count = 0
        for c in chests_l:
            trapped_keys = [k for k in c.keys if k==l]
            trapped_key_count+=len(trapped_keys)

        if keys[l]==trapped_key_count:
            return False # All keys are trapped

    return True


if __name__=='__main__':
    main()
