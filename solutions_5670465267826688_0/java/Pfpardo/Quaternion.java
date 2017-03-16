	public class Quaternion {
		private int sign;
		public int getSign() {
			return sign;
		}

		private char value;
		
		public char getValue() {
			return value;
		}

		Quaternion(char value) {
			this.sign =1;
			this.value = value;
		}
		
		void applyMult(char letra) {
			switch (this.value) {
				case '1':
					this.value = letra;
					break;
				case 'i':
					switch (letra) {
						case 'i':
							this.value = '1';
							this.sign *= -1;
							break;
						case 'j':
							this.value = 'k';
							break;
						case 'k':
							this.value = 'j';
							this.sign *= -1;
							break;
					}
					break;
				case 'j':
					switch (letra) {
						case 'i':
							this.value = 'k';
							this.sign *= -1;
							break;
						case 'j':
							this.value = '1';
							this.sign *= -1;
							break;
						case 'k':
							this.value = 'i';
							break;
					}
					break;
				case 'k':
					switch (letra) {
						case 'i':
							this.value = 'j';
							break;
						case 'j':
							this.value = 'i';
							this.sign *= -1;
							break;
						case 'k':
							this.value = '1';
							this.sign *= -1;
							break;
					}
					break;
				default:
					throw new RuntimeException("Ojo:letra no soportada");
			}
		}
		public boolean compara(char letra) {
			return (this.sign == 1) && (this.value == letra); 
		}
		
	}
