input = """30
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
hello i am the google code jam test data
how are you
aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny iynny aynny ieeeeeeeee
y n f i c w l b k u o m x s e v z p d r j g a t h a q set k oset xa ynfd
schr rkxc tesr aej dksl tkrb xc
rpysdmyrksl rchr kd ser leped drpcslrb
drpcslrb kd leped drpcslrb
wpkcsid iesr mcr wpkcsid mcr dfkcsrkwkf vpelpcdd le nekso
vscjxesejmrpyxkfpedfevkfdkmkfegemfysefeskedkd
aej vkddci eww rbc fbkfocs myia
ys cac wep ys cac ysi y vklces wep y vklces
eb byk kx ks jp fexvjrcp cyrksl aejp fbccqnjplcpd ysi leelmcpcdksl aejp rchrq
kx fexxysicp dbcvypi ysi rbkd kd xa wygepkrc vpenmcx es rbc leelmc feic uyx
tba ie vpelpyxxcpd ymtyad xkh jv bymmetccs ysi fbpkdrxyd
k bygc ncdrci wpjkr dvkoc ysi xees set k dbymm ncdr aej rbc lja
kr tyd rbc ncdr ew rkxcd kr tyd rbc nmjpdr ew rkxcd
ejp feic uyx kd mkoc rbc varbylepcys rbcepcx
rbcpc kd se ysdtcp
bet ypc aej bemiksl jv ncfyjdc kx y veryre
cyfb ew jd byd bkd ets dvcfkym lkwr ysi aej oset rbkd tyd xcysr re nc rpjc
ysi kw aej iesr jsicpcdrkxyrc xc k tesr jsicpcdrkxyrc aej
na rbc vpkfoksl ew xa rbjxnd dexcrbksl tkfoci rbkd tya fexcd
eb seeeee lellymep kd bcyici wep rbc epvbysylc
eb xa lei mcrd xyoc ejr
rbkd kd de chfkrksl k bygc re le rbc nyrbpeex
njww rpasiyxcpc ysi yxjxj
aej oset aej tysr re"""

lines = input.split("\n")

#Nombre de lignes pour un input
t = 1

for i in range(0,len(lines)-1):
	
	# Input i
	inp = lines[i+1]
	
	inp = inp.replace("a",'Y')
	inp = inp.replace("b","H")
	inp = inp.replace("c","E")
	inp = inp.replace("d","S")
	inp = inp.replace("e","O")
	inp = inp.replace("f","C")
	inp = inp.replace("g","V")
	inp = inp.replace("h","X")
	inp = inp.replace("i","D")
	inp = inp.replace("j","U")
	inp = inp.replace("k","I")
	inp = inp.replace("l","G")
	inp = inp.replace("m","L")
	inp = inp.replace("n","B")
	inp = inp.replace("o","K")
	inp = inp.replace("p","R")
	inp = inp.replace("q","Z")
	inp = inp.replace("r","T")
	inp = inp.replace("s","N")
	inp = inp.replace("t","W")
	inp = inp.replace("u","J")
	inp = inp.replace("v","P")
	inp = inp.replace("w","F")
	inp = inp.replace("x","M")
	inp = inp.replace("y","A")
	inp = inp.replace("z","Q")
	
	r = inp.lower()
	
	print "Case #"+str(i+1)+": "+r

