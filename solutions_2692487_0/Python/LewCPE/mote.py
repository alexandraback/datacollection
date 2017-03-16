

def play(armin,motes):
    for i,mote in enumerate(motes):
        if mote < armin:
            armin += mote
        elif armin == 1:
            return len(motes)
        else:
            add_oper = 0
            del_oper = 1 + play(armin,motes[i+1:])
            while armin <= mote:
                armin += armin - 1
                add_oper += 1
            armin += mote
            add_oper += play(armin,motes[i+1:])
            return min(del_oper,add_oper)
            break
    return 0

def main():
    for nocase in xrange(1,int(raw_input())+1):
        armin_size, nomote = [int(c) for c in raw_input().split()]
        mote_list = [int(c) for c in raw_input().split()]
        mote_list.sort()
        oper = play(armin_size,mote_list)
        print "Case #%d: %d" % (nocase,oper)
        
if __name__ == "__main__":
    main()
