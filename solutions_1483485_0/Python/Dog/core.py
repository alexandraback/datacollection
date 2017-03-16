
googlereses = {
        'y': 'a',        
        'w': 'y',
        'e': 'o',
        'q': 'z',
        'z': 'q',
        'k': 'i',
        'p': 'r',
        'v': 'p',
        'm': 'l',
        'n': 'b',
        'd': 's',
        'e': 'o',
        'x': 'm',
        'c': 'e',
        'l': 'g',
        's': 'n',
        'j': 'u',
        'i': 'd',
        'r': 't',
        'k': 'i',
        'p': 'r',
        'h': 'x',
        'v': 'p',
        't': 'w',
        'n': 'b',
        'a': 'y',
        'd': 's',
        'e': 'o',
        'c': 'e',
        's': 'n',
        'b': 'h',
        'w': 'f',
        'm': 'l',
        'y': 'a',
        ' ': ' ',
        'f': 'c',
        'r': 't',
        'k': 'i',
        'g': 'v',
        'o': 'k',
        'v': 'p',
        't': 'w',
        'a': 'y',
        'd': 's',
        'e': 'o',
        'u': 'j',
        'c': 'e',
        'l': 'g',
        's': 'n',
        'w': 'f',
        'j': 'u',
        'y': 'a',
        ' ': ' ',
        'r': 't'
    }

def process_input(input):
    return ''.join(googlereses.get(c, c) for c in input)

if __name__ == '__main__':
    string = """30
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
hello i am the google code jam test data
how are you
aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny ieeeeeeeee
y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd
schr rkxc tesr aej dksl tkrb xc
lpccrksld fbccdc vevdkfmc rbc sjxncp aej bygc ikymci kd fjppcsrma ejr ew vepofbevd
ip qykjd ip qykjd ip qykjd ip qykjd eeeeeeeeeeeeb ip qykjd
na rbc vpkfoksl ew xa rbjxnd dexcrbksl tkfoci rbkd tya fexcd
tbeeeeeeeeeeeeeeeeeeeyyyyyyyyy k oset f vmjd vmjd
wpkcsid iesr mcr wpkcsid mcr dfkcsrkwkf vpelpcdd le nekso
aej ncrrcp fjr rbc vkqqy ks wejp vkcfcd ncfyjdc kx ser bjslpa csejlb re cyr dkh
kx fexxysicp dbcvypi ysi rbkd kd xa wygepkrc vpenmcx es rbc leelmc feic uyx
ks y tepmi ew ikpctemgcd ysi mkesd dexcrkxcd rbc pypcdr fpcyrjpc kd y wpkcsi
eb acyb ympklbr tcpc lessy dbyoc kr jv tkrb rbc vypra ncyp resklbr
xa syxc kd ijl k bygc ujdr xcr aej ysi k meeegc aej
eb byk kx ks jp fexvjrcp cyrksl aejp fbccqnjplcpd ysi leelmcpcdksl aejp rchrq
eb seeeee lellymep kd bcyici wep rbc epvbysylc
eb xa lei mcrd xyoc ejr
w ew rte czjymd w ew esc czjymd esc
wep k ncrtccs rbpcc ysi s w ew k czjymd w ew k xksjd esc vmjd w ew k xksjd rte
bet ypc aej bemiksl jv ncfyjdc kx y veryre
rbkd bcpc kd ljsveticp yfrkgyrci rtcsra dcgcs fymkncp wjmm yjre se okfonyfo sykmrbpetksl xyabcx
tba ie vpelpyxxcpd ymtyad xkh jv bymmetccs ysi fbpkdrxyd
set rbyr aej oset leelmcpcdc vmcydc ie ser jdc kr re byfo ksre ejp dadrcxd
ys cac wep ys cac ysi y vklces wep y vklces
kr tyd rbc ncdr ew rkxcd kr tyd rbc nmjpdr ew rkxcd
k bygc ncdrci wpjkr dvkoc ysi xees set k dbymm ncdr aej rbc lja"""
    
    for i, input in list(enumerate(string.split('\n')))[1:]:
        print 'Case #%s: %s' % (i, process_input(input))
    
