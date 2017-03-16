#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int L,X;
char input[10010];

char word;

char toLowerCase(char a) {
	if(a == '_') return '1';
	if(a>= 'A' && a <= 'Z') 
		return a-'A'+'a';
	return a;
}

char switchCase(char a) {
	if(a == '1') return '_';
	if(a == '_') return '1';
	if(a >= 'A' && a <= 'Z')
		return a-'A'+'a';
	else
		return a-'a'+'A';
}

char isUpperCase(char a) {
	if(a=='_' || (a >= 'A' && a <= 'Z') ) return true;
	return false;
}

char matchCase(char a,char b,char c) {

	//printf("case: %d %d %c\n",isUpperCase(a),isUpperCase(b),c);

	if(isUpperCase(a)){
		if(isUpperCase(b)) {
			return c;
		} else {
			return switchCase(c);
		}
	} else {
		if(isUpperCase(b)) {
			return switchCase(c);
		} else {
			return c;
		}
	}
}

char mul(char a, char b) {
	if(a == '_') return switchCase(b);
	
	char la = toLowerCase(a);
	char lb = toLowerCase(b);
	
	//printf("mul: %c %c\n",a,b);
	
	char c = '1';
	
	if(la == 'i') {
		if(lb == 'i') {
			c = '_';
		} else if(lb == 'j') {
			c = 'k';
		} else if(lb == 'k') {
			c = 'J';
		} else {
			c = 'i';
		}
	} else if(la == '1') {
		c = lb;
	} else if(la == 'j') {
		if(lb == 'i') {
			c = 'K';
		} else if(lb == 'j') {
			c = '_';
		} else if(lb == 'k') {
			c = 'i';
		} else {
			c = 'j';
		}
	} else {
		if(lb == 'i') {
			c = 'j';
		} else if(lb == 'j') {
			c = 'I';
		} else if(lb == 'k') {
			c = '_';
		} else {
			c = 'k';
		}
	}
	
	return matchCase(a,b,c);
}

char solveRest(int idx) {
	char res = '1';
	
	if(idx >= L*X) return res;
	
	for(int i = idx%L;i < L;i++) {
		res = mul(res,input[i]);
	}
	int offset = 1;
	int temp = L;
	while(idx >= temp) {
		temp+=L;
		offset++;
	} 
	
	//printf("test: %d %c %c\n",idx,input[idx%L],res);
	
	for(int i = offset;i < X;i++) {
		res = mul(res,word);
	}
	//printf("solveRest: %d %c\n",offset,res);
	
	return res;
}

bool solve(char c, int idx) {
	char next = mul(c,input[idx%L]);
	
	if(idx >= X*L || idx > 8*L) return false;
	
	//printf("solve: %c \n",next);
	
	if(next == 'j') {
		if(solveRest(idx+1) == 'k') return true;
		else return false;	
	} else {
		return solve(next,idx+1);
	}
	return false;
}


char generateWord() {
	char res = '1';
	for(int i = 0; i < L;i++) {
		res = mul(res,input[i]);
	}
	return res;
}

int main() {
	scanf("%d",&T);
	for(int t = 1; t <= T;t++) {
		scanf("%d %d",&L,&X);
		scanf("%s",input);
		
		char cur = '1';
		bool pos = false;
		
		word = generateWord();
		
		for(int i = 0; i < min(4,X)*L;i++) {
			cur = mul(cur,input[i%L]);
			if(cur == 'i') {
				if(solve('1',i+1)) {
					pos = true;
				} 
			}
		}
		if(pos) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}	
}
