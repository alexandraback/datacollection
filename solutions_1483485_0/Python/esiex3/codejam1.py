rese = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

inp = '''
30
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
hello i am the google code jam test data
how are you
aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny ieeeeeeeee
y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd
schr rkxc tesr aej dksl tkrb xc
mcr mkvd ie tbyr bysid ie
aej ncrrcp fjr rbc vkqqy ks wejp vkcfcd ncfyjdc kx ser bjslpa csejlb re cyr dkh
rbkd bcpc kd ljsveticp yfrkgyrci rtcsra dcgcs fymkncp wjmm yjre se okfonyfo sykmrbpetksl xyabcx
ip qykjd ip qykjd ip qykjd ip qykjd eeeeeeeeeeeeb ip qykjd
na rbc vpkfoksl ew xa rbjxnd dexcrbksl tkfoci rbkd tya fexcd
kr tyd rbc ncdr ew rkxcd kr tyd rbc nmjpdr ew rkxcd
ejp feic uyx kd mkoc rbc varbylepcys rbcepcx
rbcpc kd se ysdtcp
tbeeeeeeeeeeeeeeeeeeeyyyyyyyyy k oset f vmjd vmjd
ymm aejp nydc ypc ncmesl re cppep rbc dveesa nypi
aej tysr dcmm rbksld yr xc neksl qeeex
k bygc ncdrci wpjkr dvkoc ysi xees set k dbymm ncdr aej rbc lja
eb acyb ympklbr tcpc lessy dbyoc kr jv tkrb rbc vypra ncyp resklbr
dtkwr yd rbc tksi zjkcr yd rbc wepcdr drcyia yd rbc xejsryks
rpysdmyrksl rchr kd ser leped drpcslrb
drpcslrb kd leped drpcslrb
xa syxc kd ijl k bygc ujdr xcr aej ysi k meeegc aej
ys cac wep ys cac ysi y vklces wep y vklces
wep rbedc tbe dvcyo ks y resljc ie ser dvcyo re erbcp vcevmc
seneia jsicpdrysid rbcx dksfc rbca ypc dvcyoksl xadrcpkcd ks rbc dvkpkr
set kd rbc djxxcp ew ejp myfo ew ikdfesrcsr
eb byk kx ks jp fexvjrcp cyrksl aejp fbccqnjplcpd ysi leelmcpcdksl aejp rchrq
'''

lines = inp.strip().splitlines()

output = ''
for x in xrange(int(lines[0])):
    output += 'Case #' + str(x+1) + ': '
    for letter in lines[x+1]:
        output += rese[letter]
    output += '\n'
